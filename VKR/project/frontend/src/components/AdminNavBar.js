import React from 'react';
import { FaUserPlus, FaUserFriends, FaWallet, FaMoneyBillAlt } from 'react-icons/fa';
import { GrLogout } from "react-icons/gr";


import { Outlet } from 'react-router-dom';

const AdminNavBar = () => {
    return (
        <div className='flex h-screen'>

            <nav className="bg-gray-800 text-white p-4 flex flex-col justify-between">
                <div className="">
                    <h2 className="text-xl font-bold mb-4">Menu</h2>
                    <ul >
                        <li className="mb-2">
                            <a href="create-user" className="pr-16 flex items-center hover:bg-gray-700 rounded-md p-2">
                                <FaUserPlus className="mr-2" />
                                Create User
                            </a>
                        </li>
                        <li className="mb-2">
                            <a href="show-users" className="pr-16 flex items-center hover:bg-gray-700 rounded-md p-2">
                                <FaUserFriends className="mr-2" />
                                Users List
                            </a>
                        </li>
                        <li className="mb-2">
                            <a href="create-wallet" className="pr-16 flex items-center hover:bg-gray-700 rounded-md p-2">
                                <FaWallet className="mr-2" />
                                Create Wallet
                            </a>
                        </li>
                        <li className="mb-2">
                            <a href="show-wallets" className="pr-16 flex items-center hover:bg-gray-700 rounded-md p-2">
                                <FaMoneyBillAlt className="mr-2" />
                                Wallets List
                            </a>
                        </li>
                        <li className="mb-2">
                            <a href="logout" className="pr-16 flex items-center hover:bg-gray-700 rounded-md p-2">
                                <GrLogout className="mr-2" />
                                Logout
                            </a>
                        </li>
                    </ul>
                </div>
            </nav>

        <div>
            <Outlet />
        </div>

        </div>


    );
};

export default AdminNavBar;
