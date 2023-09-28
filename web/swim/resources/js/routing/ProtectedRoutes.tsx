import React, { useEffect, useState } from "react";
import { Navigate } from "react-router-dom";
import { Outlet } from "react-router-dom";
import GuestLayout from "../layout/GuestLayout";

function ProtectedRoutes() {
    const [isLogged, setIsLogged] = useState(false);

    useEffect(() => {
        localStorage.getItem('authToken') ? setIsLogged(true) : setIsLogged(false);
    }, []);
    return isLogged ? (
        <>
            <Navigate to={'/home'} />
            <GuestLayout />
        </>
    ) : (
        <>
            <Navigate to={'/register'} />
            <Outlet />
        </>
    )
}

export default ProtectedRoutes;