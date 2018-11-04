/*
 * ****** COPS v7 Emulator - Open Source ******
 * Copyright (C) 2012 - 2014 Jean-Philippe Boivin
 *
 * Please read the WARNING, DISCLAIMER and PATENTS
 * sections in the LICENSE file.
 */

#include "diffiehellman.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

DiffieHellman :: DiffieHellman(const char* aP, const char* aG)
    : p(BN_new()), g(BN_new()),
      a(BN_new()), b(BN_new()),
      s(BN_new()), A(BN_new()), B(BN_new())
{
	BN_hex2bn(&p, aP);
	BN_hex2bn(&g, aG);
}

DiffieHellman :: ~DiffieHellman()
{
    if (p != nullptr)
        BN_free(p);

    if (g != nullptr)
		BN_free(g);

    if (a != nullptr)
		BN_free(a);

    if (b != nullptr)
		BN_free(b);

    if (s != nullptr)
		BN_free(s);

    if (A != nullptr)
		BN_free(A);

    if (B != nullptr)
		BN_free(B);
}

string
DiffieHellman :: generateRequest()
{
	BN_CTX *ctx;
	ctx = BN_CTX_new();

	BN_generate_prime_ex(a, 256, 30, NULL, NULL, NULL);
	BN_mod_exp(A, g, a, p, ctx);
	string request = BN_bn2hex(A);
    return request;
}

string
DiffieHellman :: generateResponse(const char* aPubKey)
{
	BN_CTX *ctx;
	ctx = BN_CTX_new();

	BN_generate_prime_ex(b, 256, 30, NULL, NULL, NULL);
	BN_mod_exp(B, g, b, p, ctx);

	BN_hex2bn(&A, aPubKey);
	BN_mod_exp(s, A, b, p, ctx);

	string response(BN_bn2hex(B));
    return response;
}

string
DiffieHellman::handleResponse(const char* aPubKey)
{
	BN_CTX *ctx;
	ctx = BN_CTX_new();

	BN_hex2bn(&B, aPubKey);
	BN_mod_exp(s, B, a, p, ctx);

	string response(BN_bn2hex(s));
    return response;
}
