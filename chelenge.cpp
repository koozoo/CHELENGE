

/*
* Special chalange №2
Для продвинутых и кому интересно... Как извесно из криптографии любое сложное шифрование можно разложить
на комбинацию замен символов и перестановок.  😎☺️ При замене символ сохраняет свою позицию но меняется на другой.
При перестановке меняется позиция символа. Напишите утилиту которая принимает параметры при запуске и зашифровывает
(используя перестановку и замену) или расшифровывает указанный файл по ключу который ввел пользователь.
Используйте генератор псевдослучайных чисил rand или QRandom и операцию XOR для шифрования заменой. 
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{ 
    std::string word, key, result;

    std::cout << "Enter your word: " << std::endl;
    getline(cin,word);

    std::cout << "Enter your key: " << std::endl;
    getline(cin, key);       

    int data_length, key_length, rnd_index, seed = 0;    

    data_length = word.size();
    key_length = key.size();


    cout << "The message is: " << word << endl;

    for (int i = 0; i < key_length; i++)
    {
        seed = seed + key[i];
    }

    srand(seed);
    result = word;
    for (int i = 0; i < data_length; i++)
    {
        
        result[i] = result[i] + key[rand() % key_length];

    }

    cout << "The cipher is: " << result << endl;

    srand(seed);

    for (int i = 0; i < data_length; i++)
    {
        result[i] = result[i] - key[rand() % key_length];

    }

    cout << "The uncipher is: " << result << endl;

    /*
    std::vector<int> swap_table;
    swap_table.resize(key_length);

    bool duble_index;

    for (int i = 0; i < key_length;)
    {
        duble_index = false;
        rnd_index = rand() % key_length;

        for (int j = 0; j < i; j++) {

            if (swap_table[j] == rnd_index) {
                duble_index = true;
                break;
            }
        }

        if (!duble_index)
        {
            swap_table[i] = rnd_index;
            i++;
        } 
    }

    std::string jumble;
    std::string secret_key;

    jumble = word;

    for (int i = 0; i < data_length; i++) {

        int index1 = i;
        int index2 = swap_table[i];

        char temp = jumble[index1];

        jumble[index1] = jumble[index2];
        jumble[index2] = temp;

    }
    
    for (int i = 0; i < data_length; i++) {
        std::cout << swap_table[i] << std::endl;
    }

    for (int i = 0; i < data_length; i++) {
        std::cout  << jumble[i];
    }
    */
    
    




    return 0;

}