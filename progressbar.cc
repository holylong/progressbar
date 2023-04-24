#include "progressbar.h"

int main(int argc, char* argv[]){
    if(argc > 1){
        ProgressBar* p = ProgressBar::Progress_new(0, 66, argv[1][0]);
        for(int i = 0; i < 66; i++){
            p->Progress_update(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }else{
        ProgressBar* p = ProgressBar::Progress_new(0, 66, '=');
        for(int i = 0; i < 66; i++){
            p->Progress_update(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    return 0;
}