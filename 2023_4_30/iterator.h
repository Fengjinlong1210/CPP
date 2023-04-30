#pragma once

namespace Fjl
{
	template<class iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<iterator, Ref, Ptr> self;
		iterator _it;

		ReverseIterator(iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			iterator tmp = _it;
			--tmp;
			return *tmp;
		}

		bool operator==(const self& it)
		{
			return _it == it._it;
		}

		bool operator!=(const self& it)
		{
			return _it != it._it;
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

	};

}
