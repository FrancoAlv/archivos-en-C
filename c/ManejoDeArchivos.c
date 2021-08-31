            Parámetro         Significa abrir el archivo en modo
                r                Lectura. El archivo debe existir
                w                Escritura. Si el archivo no existe, se crea, si existe, se sobrescribe
                a                Escritura al final del documento. Si no existe se crea
                rb               Binario. Para lectura
                r+               Lectura y escritura. El archivo debe existir
                w+               Crear un archivo para escritura. Si existe se sobrescribe
                rb+              Binario. Para actualización (lectura y escritura)

fputc(Caracter, ApuntadorArchivo) es una función nos permite escribir un caracter en el
archivo, regresa el caracter que se presionó en caso de que la operación se realice con éxito o
EOF si falló. El puntador es el que nos brinda la función fopen.

fclose(ApuntadorArchivo) guarda los cambios en el archivo, cierra la conexión y libera los
recursos usados por el apuntador.
