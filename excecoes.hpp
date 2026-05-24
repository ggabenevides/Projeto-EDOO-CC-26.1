#ifndef MAIN_PROJETO_EDOO_CC_26_1_EXCEPTIONS_H
#define MAIN_PROJETO_EDOO_CC_26_1_EXCEPTIONS_H

#include <string>

// trata ações inválidas
class AcaoInvalidaException
{
    std::string mensagem;
    public:
    AcaoInvalidaException(const std::string& msg);
    std::string getMensagem() const;
};

#endif //MAIN_PROJETO_EDOO_CC_26_1_EXCEPTIONS_H