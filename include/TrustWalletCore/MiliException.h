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

    virtual std::string& what() throw () {
        return message;
    }

private:
    std::string message;
};

static const MiliException ERROR_INFOS [] = {
    MiliException{"ok"},
    MiliException{"general error"},
    MiliException{"internal error"},
    MiliException{"low balance"},
    MiliException{"zero amount"},
    MiliException{"key miss"},
    MiliException{"wrong fee"},
    MiliException{"sign error"},
    MiliException{"too big tx"},
    MiliException{"utxo miss"},
    MiliException{"utxo insufficient"},
    MiliException{"script redeem"},
    MiliException{"script output"},
    MiliException{"script witness program"},
    MiliException{"invalid memo"},
};

const static char* E_PARAM = "param error";
const static char* E_SIGN = "sign error";