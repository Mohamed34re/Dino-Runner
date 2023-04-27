//#include "../HeaderFiles/SoundManager.h"
//
//
//SoundManager::SoundManager()
//{
//
//    duckBuffer = new SoundBuffer();
//    jumpBuffer = new SoundBuffer();
//    jump2Buffer = new SoundBuffer();
//    duckSound = new Sound();
//    jumpSound = new Sound();
//    jump2Sound = new Sound();
//  
//    duckBuffer->loadFromFile("Sounds/jumo.ogg");
//    jumpBuffer->loadFromFile("Sounds/jump.ogg");
//    jump2Buffer->loadFromFile("Sounds/jump.ogg");
//
//    duckSound->setBuffer(*duckBuffer);
//    jumpSound->setBuffer(*jumpBuffer);
//    jump2Sound->setBuffer(*jump2Buffer);
//}
//
//void SoundManager::Start()
//{
//    Music music;
//    music.openFromFile("Sounds/splash_theme.ogg");
//    music.play();
//}