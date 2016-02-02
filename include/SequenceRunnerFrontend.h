/*
 *
 *  Created on: Jul 23, 2015
 *      Author: vogt
 */

#ifndef SEQUENCERUNNERFRONTEND_H_
#define SEQUENCERUNNERFRONTEND_H_

#include "SequenceRunner.h"

#ifdef BOOST_NO_CXX11_VARIADIC_TEMPLATES
#warning cannot use variadic templates: RuntimeChooser limited to 4 arguments
#include "pre_c++11/SequenceRunnerFrontend_pre_c++11.h"
#else

template<typename Chooser, typename T, typename... Ts> class SequenceRunnerFrontend
{
public:
	typedef mpl::vector<> Seq;

	SequenceRunnerFrontend( bool runFirstChoice = false ): runFirstChoice(runFirstChoice)
	{
		init();
	}


	void run( size_t id )
	{
		if( runFirstChoice )
		{
			set( Chooser::options[0].id );
		}
		else if( Chooser::id != id )
		{
			set( id );
		}
		Chooser::run( Chooser::object );
	}

	void set( size_t id )
	{
		Chooser::id = id;
		exec();
	}

private:
	bool runFirstChoice;
	void init()
	{
		Chooser::options.clear();
		Chooser::init = true;
		exec();
		Chooser::init = false;
	}

	void exec()
	{
		typedef typename mpl::if_< mpl::bool_<(sizeof...(Ts) == 0)>, SequenceRunner<Chooser, Seq,NIL,NIL>, SequenceRunner<Chooser, Seq,Ts...,NIL> >::type VSub;
		mpl::for_each<T>( VSub() );
	}
};
#endif

#endif
