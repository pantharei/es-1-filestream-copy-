/*
1) Creare un programma che copia quanto presente nel file “miofile.txt”
nel file “copia_miofile.txt”
*/

#include <fstream>
#include <vector>

int main(){

    std::string path{"miofile.txt"};
    std::ifstream inputFile; //dichiarazione stream input per lettura su file
    inputFile.open(path); //apertura dello stream
    std::vector<std::string> string_buf;

    //fase :{fetch information} from variable 'path'
    std::string line{};
    if(inputFile.is_open()){ //check apertura stream
        while(getline(inputFile,line))
            string_buf.push_back(line);
    }

    //closing file input stream
    inputFile.close();

    //fase di scrittura su copia
    std::string copy_path = "copia_miofile.txt";
    std::ofstream outFile(copy_path);

    if(outFile.is_open()){
        for(int i = 0;i < string_buf.size(); ++i){
            outFile << string_buf[i] << std::endl;
        }
    }

    //close file output stream
    outFile.close();

    return 0;
}