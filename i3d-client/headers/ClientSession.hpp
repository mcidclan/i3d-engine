#ifndef CLIENTSESSION_HPP
#define CLIENTSESSION_HPP

	#include "Element.hpp"
	#include "ClientInformer.hpp"
	#include "ElementActionSet.hpp"

	class ClientSession : public Element
	{
		public:
			///
			ClientSession();

			///
			~ClientSession();

			///
			ClData& getData(void);

			///@{
			/// Actions.
			void aGet_data(void* const data);
			///@}

		private:
			///
			uint clientid;

			///
			ClData data;

	};

#endif

