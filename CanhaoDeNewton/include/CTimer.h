class CTimer{

private:
        long int inicio;
        long int pausa;
        bool pausado;
public:
    CTimer(){
        inicio = clock();
        pausado = false;
    }
    ~CTimer(){
    }
    double GetTempoDecorrido()
    {
        if(pausado)
            return (pausa-inicio)/(double)CLOCKS_PER_SEC;
        else
            return (clock()-inicio)/(double)CLOCKS_PER_SEC;
    }

    void Pausa(){
        if (!pausado){
            pausado = true;
            pausa = clock();
        }
    }
    void Despausa(){
        if (pausado){
            long int decorrido = pausa - inicio;
            inicio = clock() - decorrido;
            pausado = false;
        }
    }
    void Reinicia(){
        pausado = false;
        inicio = clock();
    }
    CTimer* Copia(){
        CTimer* outro = new CTimer();
        outro->inicio = inicio;
        outro->pausa = pausa;
        outro->pausado = pausado;
        return outro;
    }
};

typedef CTimer* Timer;
