/* This file is generated by pcode_autog-1.16.6
** Copyright(c) HALX99, ALL RIGHTS RESERVED.
**
** Purpose: contains all protocol message definiations and codec function
**          implementations
**
*/
#ifndef _PCODE_AUTOG_CLIENT_MESSAGES_H_
#define _PCODE_AUTOG_CLIENT_MESSAGES_H_

#include "pcode_autog_client_constants.h"
#include "pcode_autog_client_includes.h"
#include "pcode_autog_client_structures.h"

extern "C" struct lua_State;

using namespace structures;
namespace messages {

struct MsgBase {
    virtual ~MsgBase(){}
    virtual obinarystream encode(void) const { return obinarystream(); };
    virtual int decode(const char* data, int len) { return 25001; };
    virtual int decodeLua(lua_State* L) { return 25002; };
    virtual int encodeLua(lua_State* L) const { return 25002; };
    virtual int get_id(void) const { return -1; };
    virtual const char* get_className() const { return "MsgBase"; };
};

struct MsgHeader {
    uint16_t                length;
    uint16_t                command_id;
    uint16_t                version;
    uint16_t                reserved;
    uint64_t                reserved2;

    obinarystream encode(void) const;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len);

    std::string get_formated_string(void) const;
};

struct LoginReq : public MsgBase {
    std::string             username;
    std::string             password;

    obinarystream encode(void)  const override;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_LOGIN_REQ; };

    const char* get_className() const override { return "LoginReq"; };

    std::string get_formated_string(void) const;
};

struct LoginResp : public MsgBase {
    bool                    succeed;
    int32_t                 session;
    std::string             append_info;

    obinarystream encode(void)  const override;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_LOGIN_RESP; };

    const char* get_className() const override { return "LoginResp"; };

    std::string get_formated_string(void) const;
};

struct LocalErrorResp : public MsgBase {
    int16_t                 error_code;
    std::string             error_msg;

    obinarystream encode(void)  const override;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_LOCAL_ERROR_INFO; };

    const char* get_className() const override { return "LocalErrorResp"; };

    std::string get_formated_string(void) const;
};

struct MsgPeerEndpointReq : public MsgBase {
    uint32_t                user_id;

    obinarystream encode(void)  const override;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_MSG_PEER_ENDPOINT_REQ; };

    const char* get_className() const override { return "MsgPeerEndpointReq"; };

    std::string get_formated_string(void) const;
};

struct MsgPeerEndpointResp : public MsgBase {
    uint32_t                user_id;
    std::string             addr;
    uint16_t                port;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_MSG_PEER_ENDPOINT_RESP; };

    const char* get_className() const override { return "MsgPeerEndpointResp"; };

    std::string get_formated_string(void) const;
};

struct MsgGetFriendListReq : public MsgBase {
    uint32_t                user_id;

    obinarystream encode(void)  const override;

    int get_id() const override { return CID_MSG_GET_FRIENDLIST_REQ; };

    const char* get_className() const override { return "MsgGetFriendListReq"; };

    std::string get_formated_string(void) const;
};

struct MsgGetFriendListResp : public MsgBase {
    int8_t                  result;
    uint32_t                user_id;
    std::vector<UserInfo>   friends;

    // decode return the remain bytes of buffer.
    int decode(const char* data, int len) override;

    int get_id() const override { return CID_MSG_GET_FRIENDLIST_RESP; };

    const char* get_className() const override { return "MsgGetFriendListResp"; };

    std::string get_formated_string(void) const;
};

// Remark: this function just create a temp message, and it not thread-safety, don't save the pointer any time!;
//     and do not use when message large than 16384Byte, 16K.
MsgBase* temp_create_message(int command_id);
}; /*namespace messages*/


#endif

