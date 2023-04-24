#ifndef _PROGRESS_BAR_H_
#define _PROGRESS_BAR_H_

#include <iostream>
#include <thread>


class ProgressBar
{ 
    public:
        static ProgressBar* Progress_new(int cur, int total, char charocur = '='){
            static ProgressBar p(cur, total, charocur);
            return &p;
        }

        ProgressBar(int cur, int total, char charocur = '='):_cur(cur), _total(total), _charocur(charocur)
        {
            _th = std::thread(&ProgressBar::Progress_show, this);
            _th.detach();
        }

        void Progress_update(int cur){
            _cur = cur;
        }

        void Progress_set(int cur, int total){
            _cur = cur;
            _total = total;
        }

        void Progress_show(){
            std::string progressview(100, '-');
            std::fflush(stdout);
            while(_cur <= _total){
                int pos = (int)((double)_cur/(double)_total*100);
                std::string curview(pos, _charocur);
                progressview.replace(0, pos, curview);

                std::cout  << " " <<  _cur+1 << "/" << _total << " " << (double)_mstime/1000 << " s" << "\r\r" << "[" << progressview.c_str() <<  "]" << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(_step));
                _mstime += _step;
            }

            std::cout << "\r" << std::endl;
        }

    private:
        int         _total{100};
        int         _cur{0};
        int         _mstime{0};
        int         _step{200};
        char        _charocur{'='};
        std::thread _th;
};


#endif // _PROGRESS_H_