//// \file bimap_example.cpp
//// \author Sandeep Koranne, (C) 2010
//// \description Example of Boost bimap
////#include "boost/bimap.hpp"
////#include <string>
////#include <iostream>
////typedef boost::bimap< std::string, int > DICT;
////int main(int argc, char* argv[]) {
////	DICT d;
////	d.insert(DICT::value_type("Jack", 1));
////	d.insert(DICT::value_type("Jane", 2));
////	d.insert(DICT::value_type("Jill", 3));
////	for (DICT::const_iterator it = d.begin();
////		it != d.end(); ++it) {
////		std::cout << it->left << "\t" << it->right << std::endl;
////	}
////	std::cout << "-------\n";
////	for (DICT::left_map::const_iterator it = d.left.begin();
////		it != d.left.end(); ++it) {
////		std::cout << it->first << "\t" << it->second << std::endl;
////	}
////	std::cout << "-------\n";
////	for (DICT::right_map::const_iterator it = d.right.begin();
////		it != d.right.end(); ++it) {
////		std::cout << it->first << "\t" << it->second << std::endl;
////	}
////	return 0;
////}
//
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
//// \file bgl_make.cpp
//// \author Sandeep Koranne, (C) 2010
//// \description Example of BGL for dependency analysis
//#include <iostream> // messaging
//#include <fstream> // reading Make file
//#include <cassert> // assertions
//#include <vector> // vertices
//#include <list> // edges
//#include <deque> // topological sort
//#include <string> // string
//#include <sstream> // string parsing
//#include <map> // string->id
//#include <boost/graph/vector_as_graph.hpp> // BGL
//#include <boost/graph/topological_sort.hpp>// topological_sort
//typedef std::map< std::string, int > FileTable;
//FileTable gFileTable;
//std::vector< std::string > gFileNames;
//static int LookupOrAdd(const std::string& Name) {
//	int retval = gFileTable.size();
//	if (gFileTable.find(Name) == gFileTable.end()) {
//		gFileTable[Name] = retval;
//		gFileNames.push_back(Name);
//		return retval++;
//	}
//	else {
//		return gFileTable[Name];
//	}
//}
//static const size_t MAX_N = 100;
//typedef std::vector< std::list< int > > Graph;
//Graph gDependency(MAX_N);
//// the input format is simple
//// target : <dep1> <dep2> <dep3>
//static void ParseFileAndCreateGraph(const std::string& fileName) {
//	std::ifstream ifs(fileName.c_str());
//	if (!ifs) {
//		std::cerr << "Unable to open file: " << fileName << std::endl;
//		exit(1);
//	}
//	char a_line[1024];
//	ifs.getline(a_line, 1024);
//	std::string line(a_line);
//	if (line != "begin") {
//		std::cerr << "File: " << fileName << " is not a .mak file\n";
//		exit(1);
//	}
//	while (true) { // parse the remaining file
//		ifs.getline(a_line, 1024);
//		std::string line(a_line);
//		if (line == "end") break;
//			// actual parsing
//			std::istringstream sis;
//		sis.str(line);
//		std::string target; sis >> target;
//		std::string token; sis >> token;
//		if (token != ":") {
//			std::cerr << "Parsing error: " << token << " expecting : " << std::endl;
//			exit(1);
//		}
//		int target_id = LookupOrAdd(target);
//			while (sis) {
//				sis >> token;
//				if (token == ";") break;
//				int dep_id = LookupOrAdd(token);
//				gDependency[target_id].push_back(dep_id);
//			}
//	}
//}
//std::deque<int> t_order;
//static void ComputeDependency(void) {
//	boost::topological_sort(
//		gDependency, std::front_inserter(t_order),
//		boost::vertex_index_map(boost::identity_property_map()));
//}
//static void PrintDependency(void) {
//	for (std::deque<int>::reverse_iterator it = t_order.rbegin();
//		it != t_order.rend(); ++it) {
//		if (*it >= gFileNames.size()) continue;
//		std::cout << "Action " << gFileNames[*it] << std::endl;
//	}
//	std::cout << std::endl;
//}
//int main(int argc, char* argv[]) {
//	std::string Name(argv[1]);
//	ParseFileAndCreateGraph(Name);
//	ComputeDependency();
//	PrintDependency();
//	return 0;
//}