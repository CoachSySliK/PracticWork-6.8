#include <iostream>

using namespace std;

int main()
{
    start:
    int number;
    int max = 64; //рамки указываю на 1 больше потому что так работает с граничными значениями 0 и 63
    int min = -1;
    int resoult[7];
    resoult[0] = (max - min) / 2;
    char answer;
    
    cout << "Загадайте число от " << min + 1 << " до " << max - 1 << endl;
    cin >> number;

    if (number < min + 1 || number > max - 1) {
        cout << "Число надо загадать в диапазоне от " << min + 1 << " до " << max - 1 << endl;
        goto start;
    }

    int i = 0;
    answer:
    while (resoult[i] != number) {        
        cout << "Ваше число больше чем " << resoult[i] << "? (Y)es or (N)o\n";
        cin >> answer;
        //cout << answer;
        int k = i + 1;
        if (answer == 89 || answer == 121) {            
            min = resoult[i];
            resoult[k] = resoult[i] + (max - resoult[i]) / 2; //31+(63-31)/2 = 31+16 = 47
        }
        else if (answer == 78 || answer == 110) {
            max = resoult[i];
            resoult[k] = resoult[i] - (resoult[i] - min) / 2;
        }
        else {
            cout << "Ответ не понят!\n";
            i--;
            goto answer;
        }
        if (resoult[k] == resoult[i]) {
            cout << "Мне кажется Вы меня обманываете, попробуйте ещё раз!\n";
            goto start;
        }
        i++;
    }
    {
        //не буду сюда склонение добавлять, я это уже сто раз делал
        string times[2] = { " раз", "раза" };
        int ending = 0;
        if (i + 1 > 1 && i + 1 < 5) ending = 1;
        cout << "Я угадал ваше число за " << i + 1 << times[ending] << ", это: " << resoult[i] << endl;
        //решил добавить :-)
    }
    return 0;
}