# symulator-boga
Projekt zrobiony na zaliczenia z przedmiotu programowanie obiektowe w C++. Projekt oparty na bibliotece graficznej [Qt](https://www.qt.io)

### Krótki opis
Program pozwala na przeprowadzenie symulacji łańcuchu pokarmowego występującego w przyrodzie.

### Założenia
* Każde z gatunków ma określone cechy
  * maksymalny wiek życia
  * minimalna waga niezbędny do przeżycia
  * waga urodzenia
  * minimalny wiek do reprodukcji
  * normalna waga 
  * inne gatunki, które może zjeść
* Zwierzęta przemieszczają się tylko po określonym terenie
* Reprodukcja powoduje utratę masy
* Ruch powoduje utratę masy zależną od ilości pokonanego dystansu
* Ruch odbywa się turowo
* Zwierze w zależności od aktualnie posiadanej masy podejmuje odpowiedni decyzje
  * Jeśli masa przekracza określoną wartość, zwierzę dąży do reprodukcji (podąża do najbliższego zwierzęcia tego samego gatunku)
  * Jeśli masa spadnie poniżej określonej wartości, zwierzę zaczyna atakować (podąża do najbliższego zwierzęca, które może zjeść)
  * Jeżeli żaden z wyżej wymienionych warunków nie zostanie spełniony (brak występowania określonego gatunku w populacji) zwierzę porusza się losowo
  * W celu uniknięcia oscylowania masy wokół wartości *normalna waga* zastosowano [histerezę](https://pl.wikipedia.org/wiki/Histereza)

### ToDo
- [ ] Podział zwierząt ze względu na płeć
- [ ] Możliwość zmiany ustawień domyślnych z poziomu panelu 
- [ ] Statystki symulacji
- [ ] Automatyczne wprowadzanie kolejnych gatunków
