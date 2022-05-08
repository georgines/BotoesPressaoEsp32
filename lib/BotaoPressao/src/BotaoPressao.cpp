#include "BotaoPressao.h"

void BotaoPressao::criar()
{
    pinMode(pino_do_botao, INPUT_PULLUP);
    return;
}

bool BotaoPressao::pressionadoAgora()
{

    if (pinoBotaoPressionadoAgora())
    {
        atualizaContadorTempo();
        if (respostaDesbloqueadaAgora())
        {
            bloqueiaResposta();
            return true;
        }
    }
    else
    {
        if (fimContadorDeTempo())
        {
            desbloqueiaResposta();
        }
    }
    return false;
}

BotaoPressao::BotaoPressao(int pino_btn, unsigned long tempo_trv)
{
    pino_do_botao = pino_btn;
    tempo_de_trava = tempo_trv;
}

BotaoPressao::~BotaoPressao()
{
}

void BotaoPressao::bloqueiaResposta()
{
    trava = true;
}

void BotaoPressao::desbloqueiaResposta()
{
    trava = false;
}

bool BotaoPressao::respostaDesbloqueadaAgora()
{
    if (!trava)
    {
        return true;
    }
    return false;
}

bool BotaoPressao::fimContadorDeTempo()
{
    if (pegarTempoAtual() - tempo_anterior >= tempo_de_trava)
    {
        return true;
        atualizaContadorTempo();
    }
    return false;
}

void BotaoPressao::atualizaContadorTempo()
{
    tempo_anterior = pegarTempoAtual();
}

unsigned long BotaoPressao::pegarTempoAtual()
{
    return millis();
}

bool BotaoPressao::pinoBotaoPressionadoAgora()
{
    int estado_atual = digitalRead(pino_do_botao);
    bool botao_pressionado = estado_atual == LOW;
    return botao_pressionado;
}