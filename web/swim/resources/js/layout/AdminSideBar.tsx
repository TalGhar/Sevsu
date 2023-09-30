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
            <div className="flex bg-gradient-to-b from-slate-200 from-50% to-emerald-200">
                <div className={`sticky top-0 h-screen p-3 shadow-lg rounded-sm overflow-hidden transition-all ${open ? "w-1/6" : "w-10"}`}>

                    <div className="space-y-3">

                        <div className={`flex flex-row justify-between`}>

                            <div className={`flex items-center overflow-hidden transition-all ${open ? "w-full" : "w-0"}`}>
                                <h2 className={`font-bald text-3xl`}>Плыви!</h2>
                            </div>

                            <button onClick={() => { setOpen(!open); }}>
                                {open ? <ChevronLeftIcon className="w-6 h-6" /> : <ChevronRightIcon className="w-6 h-6" />}
                            </button>

                        </div>

                        <div className={`flex-col transition-all overflow-hidden ${open ? "w-full" : "w-0 hidden"}`}>

                            <nav className="pt-2 pb-4 space-y-1 text-sm">
                                <Link to="/admin/awards" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Награды</Link>
                                <Link to="/admin/history" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">История</Link>
                                <Link to="/admin/news" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Новости</Link>
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
