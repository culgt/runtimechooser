/*
 *
 *  Created on: Jul 23, 2015
 *      Author: vogt
 */

#ifndef SEQUENCERUNNER_PRE_CPP11_H_
#define SEQUENCERUNNER_PRE_CPP11_H_

#include <boost/mpl/if.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/unpack_args.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/lambda.hpp>

namespace mpl = boost::mpl;
using namespace std;
using namespace mpl::placeholders;

static const bool RUN_FIRST_CHOICE = true;

struct NIL
{
public:
	static const int value = 0;
};

template<typename Chooser, typename Seq, typename T, typename T1=NIL, typename T2=NIL> class SequenceRunner
{
public:
	template<typename S> void operator()(S)
	{
		typedef SequenceRunner<Chooser, typename mpl::push_back<Seq,S>::type,T1,T2,NIL> VSub;
		mpl::for_each<T>( VSub() );
	}
};

template<typename Chooser, typename Seq> class SequenceRunner<Chooser, Seq, NIL, NIL, NIL>
{
public:
	template<typename S> void operator()(S)
	{
		typedef typename mpl::push_back<Seq,S>::type finalSeq;

		finalSeq f;

		Chooser c;
		c( f );
	}
};


#endif
