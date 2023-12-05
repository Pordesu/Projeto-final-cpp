#include "Log_class.h"
using namespace std;

int main(){
    string aux = "/Evento ,ts:0725817600/Evento 2 ,ts:0728409666/Evento 3 ,ts:0731001600/Evento 4 ,ts:1728409720/";
    Log_class log;
    log.put_logstr(aux);
    cout << log.get_output_log(1,1,12,1) << endl;
    return 0;

}