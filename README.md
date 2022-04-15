# Microprocessor simulation (ASK 1 project and ASK 2 project)

Aplikacja stanowiącą model programowego symulatora mikroprocesora.
Należy przyjąć następujący model naszego procesora:  
• Procesor posiada cztery 16-bitowe rejestry ogólnego przeznaczenia oznaczone jako AX, BX, CX i DX;  
• Każdy z rejestrów powinien być traktowany jako para 8-bitowych rejestrów o oznaczeniach NH dla części starszej i NL
dla części młodszej gdzie N oznacza A albo B albo C albo D;  
• Lista rozkazów naszego procesora obejmuje trzy rozkazy MOV – przesłania, ADD – dodawania i SUB – odejmowania;  
• Procesor umożliwia realizację dwóch trybów adresowania: trybu rejestrowego oraz trybu natychmiastowego;  
• Program umożliwia pisanie krótkich programów z użyciem dostępnych rozkazów i trybów adresowania;  
• Program umożliwia realizację napisanych programów w trybie całościowego wykonania i w trybie pracy krokowej.  
• W trybie pracy krokowej należy zapewnić śledzenie kolejności wykonywanych instrukcji. Zalecenie to należy
zrealizować stosując numeracje linii kodu programu oraz odwołania do numeru aktualnie wykonywanej instrukcji.  
• Program symulatora umożliwia zapisanie do pliku a następnie ponowne wczytanie napisanego wcześniej programu w
celu jego dalszej edycji i ponownego uruchomienia.  


Rozszerzyć możliwości modelu programowego symulatora mikroprocesora, tak aby umożliwiał
on symulację realizacji dziesięciu funkcji przerwań procesora oferowanych przez moduł BIOS (można też użyć przerwań DOS).
Wybrane funkcje powinny być różnorodne, dotyczyć różnych zasobów komputera PC np. zegara RTC, klawiatury, monitora
ekranowego, pamięci dyskowej.
W celu realizacji wątku demonstracyjnego do zbioru nazw dotychczas realizowanych komend (MOV, ADD, SUB) należy dodać
INTxx, INTyy, INTzz, ….. , gdzie xx, yy, zz, …. oznaczają numery wybranych przerwań. W programie należy utworzyć STOS
służący do przechowywania zawartości rejestrów procesora na czas wykonywania przerwań. (Szczegółowy opis mechanizmu
wywoływania przerwań procesora zostanie podany przez prowadzącego w odrębnym załączniku.)


![image](https://user-images.githubusercontent.com/28922780/163547054-dfeef975-a14a-4773-8f38-795721af1e99.png)


![image](https://user-images.githubusercontent.com/28922780/163547623-229fd2cd-eee0-48bf-bca2-48adf35b57b8.png)
