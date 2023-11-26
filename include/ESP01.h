/* ESP-01 Wi-Fi module */

#pragma once

#include "Component.h"

class ESP01 : public Component{
    private:


    public:
        ESP01();
        ~ESP01();

        void print() const override;
        void read() override;
        void send(char* data);
        void start() override;    

        int countTrueCommand;
        int countTimeCommand;
        bool found;

        int latitude;
        int longitude;
        int altitude;
        int temperatura;
        int pressao;
        int umidade;
        int velocidadeVento;
        const char* direcaoVento;
        int indiceUV;
        int intensidadeLuminosa;
        bool chuva;
        int volumeChuva;
        int porcentagemBaterias;
        int tensaoEletricaPlacaSolar;
        const char* orientacaoPlacaSolar;

        bool sendCommand(String command, int maxTime, String readReplay);
        void begin(int baudRate);
        void sendData(int tamdoc, StaticJsonDocument<384> doc);
        void printResponse();
};