#pragma once
#include "RBTree.h"

namespace zx
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		// ≤Â»Î
		bool insert(const pair<K, V>& kv)
		{
			return _t.insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};
}