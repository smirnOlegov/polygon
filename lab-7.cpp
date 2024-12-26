#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string smallestBeautifulString(string s, int k) {

        int n = s.size();
        int pos = -1;

        // Попробуем изменить строку, начиная с конца
        //O(n)
        for (int i = n - 1; i >= 0 && pos < 0; --i) {

            int cur = s[i] - 'a';
            cur++;

            //O(k)
            while (cur < k && pos < 0) {

                if (!isBeautiful(s, i, cur)) {
                    s[i] = cur + 'a';
                    pos = i;
                }
                
                cur++;
            }
        }

        // Если позиция для изменения не найдена, возвращаем пустую строку
        if (pos < 0){
            return "";
        }

        // Заполняем оставшуюся часть минимальными символами
        //O(k*n)
        fillRemaining(s, pos + 1, k);

        return s;
    }

private:
    // Проверяем, не будет ли текущий символ формировать палиндром
    bool isBeautiful(const string &s, int i, int cur) {

        if (i - 1 >= 0 && (s[i - 1] - 'a') == cur){
            return true; // Палиндром длины 2
        }
        if (i - 2 >= 0 && (s[i - 2] - 'a') == cur){
            return true; // Палиндром длины 3
        }

        return false;
    }

    // Заполняем строку, начиная с позиции start, минимальными символами
    void fillRemaining(string &s, int start, int k) {

        int n = s.size();

        for (int i = start; i < n; ++i) {
            for (int j = 0; j < k; ++j) {

                if (!isBeautiful(s, i, j)) {
                    s[i] = j + 'a';

                    break;
                }
            }
        }
    }
};

//memory O(1) ничего лишнего не храним: счётчики, индексы, текущий символ
//time O(k*n) 
