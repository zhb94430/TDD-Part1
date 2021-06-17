class Pair
{
public:
	std::string from;
	std::string to;

	Pair(std::string _from, std::string _to)
	{ from = _from; to = _to; };

	bool operator==(const Pair& other) const
	{ return (from == other.from) && (to == other.to); };

	bool operator<(const Pair& other) const
	{
		return from < other.from;
	}	
};