/*
 * ****** COPS v7 Emulator - Open Source ******
 * Copyright (C) 2012 - 2014 Jean-Philippe Boivin
 *
 * Please read the WARNING, DISCLAIMER and PATENTS
 * sections in the LICENSE file.
 */

#ifndef _COPS_V7_EMULATOR_MSG_LOGIN_CHALLENGE_S_H_
#define _COPS_V7_EMULATOR_MSG_LOGIN_CHALLENGE_S_H_

#include "msg.h"

/**
 * Diffie-Hellman response to a request (B key). It will help to compute
 * the final shared S key.
 */
class MsgLoginChallengeS : public Msg
{
public:
    /** The number of bytes of the padding. */
    static const size_t PADDING_LEN = 7;

public:
    /* Unused internally ! */
    #pragma pack(push, 1)
    typedef struct
    {
        uint8_t Padding[MsgLoginChallengeS::PADDING_LEN];
        int32_t Size;
        int32_t JunkSize;
        uint8_t Junk[1];
        int32_t BSize;
        char B[1];
    }MsgInfo;
    #pragma pack(pop)

public:
    MsgLoginChallengeS(const char *B);

    /* destructor */
    virtual ~MsgLoginChallengeS();


private:
    /* internal swapping of the integers for neutral-endian support */
};

#endif // _COPS_V7_EMULATOR_MSG_LOGIN_CHALLENGE_S_H_
