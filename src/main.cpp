//
// Created by pachi on 5/6/19.
//

#include <iostream>
#include "pca.h"
#include "eigen.h"
#include <fstream>

int main(int argc, char** argv){

	std::string line;

	PCA pca = new PCA(4);

	std::vector<std::vector<unsigned int> > entries;

	std::ifstream file (argv[1]); //a.out ../data/test.csv etc

	getline(file, line); //skip labels

	while (getline(file, line)){
		std::vector<unsigned int> numbers;

		//copied from SO
		std::string delimiter = ",";
		size_t pos = 0;
		std::string token;
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			numbers.push(stoi(token, nullptr));
			line.erase(0, pos + delimiter.length());
		}

		entries.push(numbers);
	}

	//acá ejecutar PCA(entries) o KNN(entries), pero creo que hay que cambiar algo del tipo

	pca.fit(entries)

	return 0;
}
