#include "excecoes.hpp"

AcaoInvalidaException::AcaoInvalidaException(const std::string& msg) : mensagem(msg) { }

std::string AcaoInvalidaException::getMensagem() const
{
    return mensagem;
}
