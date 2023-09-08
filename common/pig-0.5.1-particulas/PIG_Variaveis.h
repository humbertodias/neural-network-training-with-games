#define M_Radi 0.01745329251994329576

Jogo jogo=NULL;

PIG_Evento PIG_evento;
PIG_Teclado PIG_meuTeclado;
int PIGTeclasControle = 0;
int PIGTeclasReturn = 0;

int PIG_ExistenciaObjeto[MAX_OBJETOS] = {0};
int PIG_ExistenciaTimer[MAX_TIMERS] = {0};

int PIG_JogoRodando = 0;

float CameraPosX = 200, CameraPosY = -100;
float CameraZoom = -0.75;//-0.5;
float CameraRotationXY = 0, CameraRotationZ = 0;//40;
