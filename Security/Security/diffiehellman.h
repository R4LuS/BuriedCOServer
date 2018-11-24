/*
 * ****** COPS v7 Emulator - Open Source ******
 * Copyright (C) 2012 - 2014 Jean-Philippe Boivin
 *
 * Please read the WARNING, DISCLAIMER and PATENTS
 * sections in the LICENSE file.
 */

#ifndef _COPS_V7_EMULATOR_DIFFIE_HELLMAN_H_
#define _COPS_V7_EMULATOR_DIFFIE_HELLMAN_H_

#include "../../Common/common.h"
#include <string>

#include "openssl/bn.h"

/**
 * Diffie-Hellman key exchange implementation.
 */
class DiffieHellman
{
public:
    /**
     * Create a new exchange based on specified p & g keys.
     *
     * @param[in]   aP     the p key as a base 16 string
     * @param[in]   aG     the g key as a base 16 string
     */
    DiffieHellman(const char* aP, const char* aG);

    /* destructor */
    ~DiffieHellman();

    /**
     * Generate a new request.
     *
     * @returns the A key as a base 16 string
     */
    std::string generateRequest();

    /**
     * Generate a new response based on the public A key.
     *
     * @param[in]   aPubKey    the public request (A key)
     *
     * @returns the B key as a base 16 string
     */
    std::string generateResponse(const char* aPubKey);

    /**
     * Handle the response (B key) to generate the final key (s key).
     *
     * @param[in]   aPubKey    the public response (B key)
     *
     * @returns the s key as a base 16 string
     */
	std::string handleResponse(const char* aPubKey);

public:
    BIGNUM *p; //!< public p key
	BIGNUM *g; //!< public g key
	BIGNUM *a; //!< private a key (request)
	BIGNUM *b; //!< private b key (response)
	BIGNUM *s; //!< final key (s)
	BIGNUM *A; //!< public A key (request)
	BIGNUM *B; //!< public B key (response)
};

#endif // _COPS_V7_EMULATOR_DIFFIE_HELLMAN_H_
