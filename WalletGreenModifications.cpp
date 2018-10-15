bool WalletGreen::isValidPassword(const std::string& path, const Crypto::chacha8_key &key)
{
    static bool init = false;

    static ContainerStoragePrefix *prefix;

    Crypto::SecretKey priv;
    Crypto::PublicKey pub;

    /* Don't do this each call, just do it once for speed */
    if (!init)
    {
        m_containerStorage.open(path, FileMappedVectorOpenMode::OPEN, sizeof(ContainerStoragePrefix));
        prefix = reinterpret_cast<ContainerStoragePrefix*>(m_containerStorage.prefix());
        init = true;
    }

    uint64_t creationTimestamp;

    decryptKeyPair(prefix->encryptedViewKeys, m_viewPublicKey, m_viewSecretKey, creationTimestamp, key);

    if (!validKeys(m_viewSecretKey, m_viewPublicKey))
    {
        return false;
    }

    decryptKeyPair(m_containerStorage[0], pub, priv, creationTimestamp, key);

    return validKeys(priv, pub);
}

bool WalletGreen::validKeys(const Crypto::SecretKey &secretKey, const Crypto::PublicKey &expected)
{
    Crypto::PublicKey actual;

    bool r = Crypto::secret_key_to_public_key(secretKey, actual);

    return (r && expected == actual);
}
