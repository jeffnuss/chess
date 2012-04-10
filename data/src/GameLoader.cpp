/*
 * GameLoader.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#include "../inc/GameLoader.h"
#include "../inc/CS240Exception.h"
#include "../inc/URLInputStream.h"
#include "../inc/HTMLToken.h"
#include "../inc/HTMLTokenizer.h"
#include "../inc/HTTPInputStream.h"


using namespace std;

GameLoader::GameLoader() {
	// TODO Auto-generated constructor stub

}

GameLoader::~GameLoader() {
	// TODO Auto-generated destructor stub
}

MoveHistory GameLoader::LoadGame(const string & filePath, Board * boardPtr, MoveHistory * gameHistory) const
{
	try
	{
		string urlToLoad = "file://" + filePath;
		URLInputStream * stream = new URLInputStream(urlToLoad);
	}
    catch (exception &e)
    {
        cout << "Exception Occurred:" << e.what() << endl;
    }
    catch (CS240Exception &e)
    {
        cout << "Exception Occurred:" << e.GetMessage() << endl;
    }
	catch (...)
	{

	}

}
