#ifndef MY_STRTOK
#define MY_STRTOK

#include <iostream>
#include <cstring>

char* myStrtok(char* str, const char* delimiter) {
    static char* buffer = nullptr;
    if (str != nullptr)
        buffer = str;
    else if (buffer == nullptr)
        return nullptr;

    char* token = buffer;
    char* delimiterPtr = std::strpbrk(buffer, delimiter);
    bool insideQuotes = false;  // Variable para rastrear si estamos dentro de comillas
    bool quotesClosed = true;  // Variable para rastrear si las comillas se cierran

    while (delimiterPtr != nullptr) {
        char* doubleQuotesPtr = std::strchr(buffer, '\"');
        if (doubleQuotesPtr != nullptr && doubleQuotesPtr < delimiterPtr) {
            // Estamos dentro de comillas
            insideQuotes = !insideQuotes;
            quotesClosed = !quotesClosed;
        }

        // Si encontramos un número par de comillas y no estamos dentro de comillas
        // (lo que significa que estamos fuera de las comillas abiertas y cerradas),
        // entonces dividimos la cadena en un token en el delimitador actual.
        if (quotesClosed && !insideQuotes) {
            *delimiterPtr = '\0';
            buffer = delimiterPtr + 1;
            return token;
        }

        delimiterPtr = std::strpbrk(delimiterPtr + 1, delimiter);
    }
   

    // Si llegamos aquí, no se encontraron más delimitadores
    if (*buffer) {
        token = buffer;
        buffer = nullptr;
        return token;
    }

    return nullptr;
}

#endif