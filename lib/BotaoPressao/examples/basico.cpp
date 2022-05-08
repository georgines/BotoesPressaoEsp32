#include "Arduino.h"
#include "BotaoPressao.h"

const int BOTAO = 27;
const int CANAL_DO_PWM = 0;

BotaoPressao meuBotao(BOTAO);

void setup()
{
    Serial.begin(115200);
    meuBotao.criar();
}

void loop()
{
    if (meuBotao.pressionadoAgora())
    {
        Serial.println("O Botao foi pressionado agora");
    }
}
