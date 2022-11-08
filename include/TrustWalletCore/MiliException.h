#pragma once

#include <string>

/*
class MiliException
{
private:
    std::string message;

public:
    MiliException(std::string str) : message{str} {}
    std::string what() const { return message; }
};
*/

class MiliException
{
public:
    MiliException() : message("Error."){}
    MiliException(std::string str) : message(str) {}
    ~MiliException() throw () {}

    virtual const std::string& what() const throw () {
        return message;
    }

private:
    std::string message;
};

static const MiliException ERROR_INFOS [] = {
    MiliException{"ok"},
    MiliException{"general error"}, //1
    MiliException{"internal error"},
    MiliException{"low balance"},
    MiliException{"zero amount"},
    MiliException{"key miss"},
    MiliException{"wrong fee"},
    MiliException{"sign error"},
    MiliException{"too big tx"},
    MiliException{"utxo miss"},
    MiliException{"utxo insufficient"}, //10
    MiliException{"script redeem"},
    MiliException{"script output"},
    MiliException{"script witness program"},
    MiliException{"invalid memo"},

    MiliException{"invalid key"},  //15
    MiliException{"invalid address"},
    MiliException{"invalid utxo"},
    MiliException{"invalid utxo amount"},
    MiliException{"input parse fail"},
    MiliException{"no support n2n"}, //10
    MiliException{"sign count error"},
    MiliException{"invalid params"},
    MiliException{"invalid token amount"},
};

const static char* E_PARAM = "param error";
const static char* E_SIGN = "sign error";