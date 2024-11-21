#pragma once
#include "RBTree.h"

namespace zx
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		// ≤Â»Î
		bool insert(const K& key)
		{
			return _t.insert(key);
		}

	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}