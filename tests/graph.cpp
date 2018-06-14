#include <catch.hpp>
#include <sstream>

#include "graph.hpp"


TEST_CASE("Test my graph")
{
	graph_t graph(4);
	std::string input
	{
		"0 1 0 0 \n"
		"1 0 1 1 \n"
		"0 0 0 0 \n"
		"0 0 0 0 \n"
	};
	std::istringstream stream(input);
	graph.read(stream);
	std::vector<unsigned> result;
	result = graph.dfs(1);
	std::ostringstream output;
	graph.res_graph(output, result);

	std::string res_out = "2 1 3 4 ";
	REQUIRE(res_out == output.str());
}

TEST_CASE("Diagonal element is nonzero")
{
	bool flag = false;
	try {
		graph_t graph(4);
		std::string input
		{
			"0 1 0 0 \n"
			"1 1 1 1 \n"
			"0 0 0 0 \n"
			"0 0 0 0 \n"
		};
		std::istringstream stream(input);
		graph.read(stream);
	}
	catch (std::invalid_argument)
	{
		flag = true;
	}
	REQUIRE(flag);
}

TEST_CASE("The entered element is not equal to zero or one")
{
	bool flag = false;
	try {
		graph_t graph(4);
		std::string input
		{
			"0 1 0 0 \n"
			"1 9 1 1 \n"
			"0 0 0 0 \n"
			"0 0 0 0 \n"
		};
		std::istringstream stream(input);
		graph.read(stream);
	}
	catch (std::invalid_argument)
	{
		flag = true;
	}
	REQUIRE(flag);
}
