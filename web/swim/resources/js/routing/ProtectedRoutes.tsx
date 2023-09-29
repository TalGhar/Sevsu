import React from "react";
import { Navigate } from "react-router-dom";
import { Outlet } from "react-router-dom";
import GuestLayout from "../layout/GuestLayout";

function ProtectedRoutes() {
    const isLogged = localStorage.getItem('authToken');

    return isLogged ? (
        <>
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