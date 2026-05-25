#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

// trata ações inválidas
class AcaoInvalidaException
{
    std::string mensagem;
    public:
    AcaoInvalidaException(const std::string& msg);
    std::string getMensagem() const;
};

#endif