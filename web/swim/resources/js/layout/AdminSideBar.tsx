import React from "react";
import { Link, Outlet } from "react-router-dom";
import { ChevronRightIcon, ChevronLeftIcon } from "@heroicons/react/24/solid"

type Props = {
    open: boolean;
    setOpen(open: boolean): void;
}

export default function AdminSideBar({ open, setOpen }: Props) {

    return (
        <>
            <div className="flex">
                <div className={`flex flex-col h-screen p-3 bg-white shadow max-[1024px]:hidden overflow-hidden transition-all ${open ? "w-64" : "w-10"}`}>

                    <div className="space-y-3">

                        <div className={`flex flex-row justify-between`}>

                            <div className={`flex items-center overflow-hidden transition-all ${open ? "w-full" : "w-0"}`}>
                                <h2 className={`font-bald text-xl`}>Dashboard</h2>
                            </div>

                            <button onClick={() => { setOpen(!open); }}>
                                {open ? <ChevronLeftIcon className="w-4 h-4" /> : <ChevronRightIcon className="w-4 h-4" />}
                            </button>

                        </div>

                        <div className={`flex-col transition-all overflow-hidden ${open ? "w-full" : "w-0"}`}>

                            <nav className="pt-2 pb-4 space-y-1 text-sm">
                                <Link to="/admin/awards" className="flex items-center p-2 space-x-3 rounded-md">Awards</Link>
                                <Link to="/admin/history" className="flex items-center p-2 space-x-3 rounded-md">History</Link>
                                <Link to="/admin/news" className="flex items-center p-2 space-x-3 rounded-md">News</Link>
                                <Link to="/admin/requests" className="flex items-center p-2 space-x-3 rounded-md">Requests</Link>
                                <Link to="/admin/reviews" className="flex items-center p-2 space-x-3 rounded-md">Reviews</Link>
                                <Link to="/admin/services" className="flex items-center p-2 space-x-3 rounded-md">Services</Link>

                            </nav>

                        </div>
                    </div>
                </div>

                <div className="w-full h-full">
                    <Outlet />
                </div>
            </div>
        </>
    );

}
