#pragma once
#include "Arduino.h"
class BotaoPressao
{

private:
    bool trava = false;
    int pino_do_botao = 0;
    unsigned long tempo_anterior = 0;
    unsigned long tempo_de_trava = 0;

public:
    void criar();
    bool pressionadoAgora();
    BotaoPressao(int pino_btn, unsigned long tempo_trv = 250);
    ~BotaoPressao();

private:
    void bloqueiaResposta();
    void desbloqueiaResposta();
    bool respostaDesbloqueadaAgora();
    bool fimContadorDeTempo();
    void atualizaContadorTempo();
    unsigned long pegarTempoAtual();
    bool pinoBotaoPressionadoAgora();
};