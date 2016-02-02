/*
 *
 *  Created on: Jul 23, 2015
 *      Author: vogt
 */

#ifndef SEQUENCERUNNERFRONTEND_PRE_CPP11_H_
#define SEQUENCERUNNERFRONTEND_PRE_CPP11_H_

template<typename Chooser, typename T0, typename T1=NIL, typename T2=NIL, typename T3=NIL> class SequenceRunnerFrontend
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
		typedef SequenceRunner<Chooser, Seq,T1,T2,T3> VSub;
		mpl::for_each<T0>( VSub() );
	}
};

#endif
