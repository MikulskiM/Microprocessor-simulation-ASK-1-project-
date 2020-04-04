# Microprocessor simulation (ASK 1 project)
Zadanie 1.
Wykorzystując dowolny język programowania dla komputerów w standardzie PC napisać aplikację stanowiącą model
programowego symulatora mikroprocesora. Program powinien mieć przyjazny interfejs użytkownika graficzny lub znakowy do
uznania przez autorów. Należy przyjąć następujący model naszego procesora:  
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
  
Opracowanemu programowi powinna towarzyszyć dokumentacja – sprawozdanie. Sprawozdanie powinno zawierać:  
• Sformułowanie zadania wraz z przyjęciem założeń szczegółowych np. w zakresie stosowanej składni, separatorów kodów
mnemotechnicznych i argumentów itd.;  
• Opis przyjętych rozwiązań programowych zilustrowanych ewentualnie fragmentami kodu (nie zamieszczać wydruków całych
programów!) dotyczących kluczowych kwestii programu np. parsing linii programu;  
• Dyskusję osiągniętych wyników z wskazaniem wad i zalet napisanej aplikacji.
