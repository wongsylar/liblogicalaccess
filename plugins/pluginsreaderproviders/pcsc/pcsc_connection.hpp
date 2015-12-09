//
// Created by xaqq on 8/3/15.
//

#ifndef LIBLOGICALACCESS_PCSC_CONNECTION_HPP
#define LIBLOGICALACCESS_PCSC_CONNECTION_HPP

#include "pcscreaderunitconfiguration.hpp"

namespace logicalaccess
{
    /**
     * Abstract away a PCSC connection.
     *
     */
    class PCSCConnection
    {
    public:
        /**
         * Establish the PCSC connection
         */
        PCSCConnection(PCSCShareMode mode,
                       unsigned long protocol,
                       SCARDCONTEXT context,
                       const std::string &device);

        /**
         * Disconnects the PCSC connection
         */
        ~PCSCConnection();

		void reconnect();

		/**
		 * Check for a PCSC error in error_flag.
		 *
		 * Return a string corresponding to the error, or an empty
		 * string if no error.
		 */
		static std::string strerror(unsigned int error_flag);

		/**
		* Set the action to take on the card in the connected reader on close.
		*/
		void setDisposition(DWORD dispo) { disposition_ = dispo; }

        /**
         * Returns the handler associated with the connection.
         */
        SCARDHANDLE getHandle() const;

	private:

        /**
         * The handle.
         */
        SCARDHANDLE handle_;

        /**
         * The share mode.
         */
        PCSCShareMode share_mode_;

        /**
         * The protocol.
         */
        DWORD protocol_;

		/**
		 * The activated protocol
		 */
		DWORD active_protocol_;

		/**
		* Action to take on the card in the connected reader on close.
		*/
		DWORD disposition_;

		friend class PCSCReaderUnit;
    };
}

#endif //LIBLOGICALACCESS_PCSC_CONNECTION_HPP