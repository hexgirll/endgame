// #include  "header.h"

// void InitSounds(GameMedia *gameMedia){

//     InitAudioDevice();
//     gameMedia->grassRunningSound = LoadSound("resource/audio/grass_running.mp3");
//     SetSoundVolume(gameMedia->grassRunningSound, 0.5f);  // Full volume
    
    

// }


// void CleanupSounds(GameMedia *gameMedia) {
//     UnloadSound(gameMedia->grassRunningSound);
//     UnloadMusicStream(gameMedia->tensionMusic);
//     CloseAudioDevice();  // Close the audio device after all sounds/music are unloaded
// }

// void HandlePlayerMovement(GameMedia *gameMedia, e_move move) {
//     if (move == RUN){
//         if (!IsSoundPlaying(gameMedia->grassRunningSound)) {
//             PlaySound(gameMedia->grassRunningSound);  
//         }
//     } else {
//         if (move == IDLE || !IsSoundPlaying(gameMedia->grassRunningSound)) {
//             StopSound(gameMedia->grassRunningSound); 
//         }
//     }
// }

