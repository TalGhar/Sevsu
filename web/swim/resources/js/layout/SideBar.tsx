import React from "react";
import { Link, Outlet } from "react-router-dom";
import { ChevronRightIcon, ChevronLeftIcon } from "@heroicons/react/24/solid"

type Props = {
    open: boolean;
    dropDownOpen: boolean;
    setOpen(open: boolean): void;
    setDropDownOpen(dropDownOpen: boolean): void;
}

export default function SideBar({ open, setOpen, dropDownOpen, setDropDownOpen }: Props) {

    const isLogged = localStorage.getItem('authToken');

    const logOut = () => {
        localStorage.removeItem('authToken');
        localStorage.removeItem('userId');
        window.location.href = '/register';

    }

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



                                {isLogged ? (
                                    <div>
                                        <Link to="/home" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Главная</Link>
                                        <Link to="/news" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Новости</Link>

                                        <div onMouseEnter={() => { setDropDownOpen(true); }}
                                            onMouseLeave={() => { setDropDownOpen(false); }}>

                                            <Link to="/about" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">О компании</Link>

                                            <div className={`transition-all overflow-hidden duration-500 ease-in-out ${dropDownOpen ? "" : "hidden"} `}>
                                                <div className="flex flex-col m-2">
                                                    <Link to="/about/#history" className="items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-md space-x-3 rounded-md">История</Link>
                                                    <Link to="/about/#services" className="items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-md space-x-3 rounded-md">Услуги</Link>
                                                    <Link to="/about/#awards" className="items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-md space-x-3 rounded-md">Награды</Link>
                                                </div>
                                            </div>

                                        </div>

                                        <Link to="/sales" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Продажа катеров/яхт</Link>
                                        <Link to="/place" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Выставить свой транспорт</Link>
                                        <button className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md" onClick={logOut}>Выйти из аккаунта</button>

                                    </div>

                                ) : (
                                    <div>
                                        <Link to="/home" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Главная</Link>
                                        <Link to="/register" className="flex items-center p-2 duration-150 hover:shadow-md hover:bg-slate-100 text-lg space-x-3 rounded-md">Войти в аккаунт</Link>
                                    </div>)}

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
