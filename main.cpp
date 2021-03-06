#include <iostream>
#include "Evolution.h"
#include "params.h"

using namespace std;

int MUTATIONPROB;
int MUTATEDGENES;
int CROSSOVERPROBABILITY;
int TOURNAMENTSIZE;
int POPSIZE;
int MAXGENERATIONS;
int STATES;
int NEIGHBOURHOOD;
int SIMULATIONSTEPS;
int SIZEOFCA;
int MINRULES;
int MAXRULES;
string FILENAME;
int MAXFITENSS;

int main(int argc, char* argv[]) {
//argumenty 90 6 80 15 1 stats-rucne 60
  //90 6 80 15 1 stats-rucne 60
  MUTATIONPROB = 90;
  MUTATEDGENES = 6;
  CROSSOVERPROBABILITY = 80;
  TOURNAMENTSIZE = 15;
  POPSIZE = 20;
  MAXGENERATIONS = 60;
  STATES = 7;
  NEIGHBOURHOOD = 9;
  SIMULATIONSTEPS = 30;
  SIZEOFCA = 45;
  MINRULES = 10;
  MAXRULES = 15;
  FILENAME = "3";
  MAXFITENSS = (STATES*STATES*(SIZEOFCA-1)*(SIZEOFCA-1)) / (STATES*NEIGHBOURHOOD) * MAXRULES;
//  MAXFITENSS = 999999999;
  string FILENAMESTATS = "stats-rucne";

  if(argc == 8){
    MUTATIONPROB = stoi (argv[1],nullptr,10);
    MUTATEDGENES = stoi (argv[2],nullptr,10);
    CROSSOVERPROBABILITY = stoi (argv[3],nullptr,10);
    TOURNAMENTSIZE = stoi (argv[4],nullptr,10);
    FILENAME = argv[5];
    FILENAMESTATS = argv[6];
    MAXGENERATIONS = stoi (argv[7],nullptr,10);;

    cout <<MAXGENERATIONS<<" max fit = "<<MAXFITENSS <<" "<< MUTATIONPROB<<" " << MUTATEDGENES<<" " << CROSSOVERPROBABILITY<<" "<<TOURNAMENTSIZE<<" "<<FILENAME<<endl;
  }

  time_t seed = time(0);
  srand(seed);

  Evolution evolution;
  evolution.initialize();
  evolution.evolve();
  evolution.exportChromosome(std::__cxx11::string());


//    Chromosome c;
//    c.initialize();
//    c.calculateFittness();
//    c.exportCA();
//    cout << "fitness " << c.fittness << endl;

  string filename = "bicas/" + FILENAME + "info";
  cout << filename << endl;
  ofstream fout(filename, std::ofstream::out);
  ofstream statsOut(FILENAMESTATS, std::ofstream::app);


  fout << "Filename" << ",";
  fout << "Fittness" << ",";
  fout << "Seed" << ",";
  fout << "MUTATIONPROB" << ",";
  fout << "MUTATEDGENES" << ",";
  fout << "CROSSOVERPROBABILITY" << ",";
  fout << "TOURNAMENTSIZE" << ",";
  fout << "POPSIZE" << ",";
  fout << "MAXGENERATIONS" << ",";
  fout << "STATES" << ",";
  fout << "NEIGHBOURHOOD" << ",";
  fout << "SIMULATIONSTEPS" << ",";
  fout << "SIZEOFCA" << ",";
  fout << "MINRULES" << ",";
  fout << "MAXRULES" << ",";
  fout << endl;

  fout << FILENAME << ",";
  fout << evolution.bestEver.fittness << ",";
  fout << seed << ",";
  fout << MUTATIONPROB << ",";
  fout << MUTATEDGENES << ",";
  fout << CROSSOVERPROBABILITY << ",";
  fout << TOURNAMENTSIZE << ",";
  fout << POPSIZE << ",";
  fout << MAXGENERATIONS << ",";
  fout << STATES << ",";
  fout << NEIGHBOURHOOD << ",";
  fout << SIMULATIONSTEPS << ",";
  fout << SIZEOFCA << ",";
  fout << MINRULES << ",";
  fout << MAXRULES << ",";
  fout << endl;

  statsOut << FILENAME << ",";
  statsOut << evolution.bestEver.fittness << ",";
  statsOut << seed << ",";
  statsOut << MUTATIONPROB << ",";
  statsOut << MUTATEDGENES << ",";
  statsOut << CROSSOVERPROBABILITY << ",";
  statsOut << TOURNAMENTSIZE << ",";
  statsOut << POPSIZE << ",";
  statsOut << MAXGENERATIONS << ",";
  statsOut << STATES << ",";
  statsOut << NEIGHBOURHOOD << ",";
  statsOut << SIMULATIONSTEPS << ",";
  statsOut << SIZEOFCA << ",";
  statsOut << MINRULES << ",";
  statsOut << MAXRULES << ",";
  statsOut << endl;



  fout.close();
  statsOut.close();

  return 0;

}