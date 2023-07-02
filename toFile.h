#include"Utils/myStrtok.h"
#include"File.h"

void File::toFile() {
 
    ifstream csvFile(this->csv);
    ofstream test("./test");

    if(!csvFile.is_open()) {
        cout<<"Error openning csv file"<<endl;
        return;
    }

    int count = 0;
    int total = 0;
    int prevTotal = total;

    int position = 1;
    int i = 0;

    streampos prevPosition = csvFile.tellg();


    long long int lastWord = 0;

    bool isCompleteToken;

    while (csvFile){

        
        csvFile.seekg(position - 1);
        csvFile.read(buffer, lenBuffer - 1);
        streamsize bufferBytes = csvFile.gcount();
        //cout.write(buffer, bufferBytes);
        
        buffer[lenBuffer - 1] = '\0';
        char * token = myStrtok(buffer, ",");
        
        while (token != nullptr)
        {
            if(count % 12 == 0) {
                count = 0;
                total++;
            }

            

            test<<count<<" -> ";
            
            test.write(token, strlen(token));
            test<<" : "<<total<<endl;
            prevTotal = total;
            
            //prevPosition = currentPosition;
         
            total += strlen(token) + 1;

            lastWord = strlen(token);

            token = myStrtok(nullptr, ",");
            count++;
        }

        test<<"Total: "<<total<<endl;       
        
        i++;

        streampos currentPosition = csvFile.tellg();

        if(buffer[lenBuffer - lastWord - 1] == '\"' || buffer[lenBuffer - 1] != ',') {
            position = prevTotal;
            total = prevTotal;
            test<<"Position --> "<<position<<endl;
            count--;
        } else {
            position = total;
        }

        //if(i == 2) break;
    }
    
    csvFile.close();
}