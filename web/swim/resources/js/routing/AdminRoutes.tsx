import React from "react";
import { Navigate } from "react-router-dom";
import { Outlet } from "react-router-dom";
import AdminLayout from "../layout/AdminLayout";

function AdminRoutes() {

    const isAdminLogged = localStorage.getItem('isAdmin');

    return isAdminLogged ? (
        <>
            <Navigate to={'/admin/awards'} />
            <AdminLayout />
            
        </>
    ) : (
        <>
            <Navigate to={'/admin/login'} />
            <Outlet />
        </>
    )
}

export default AdminRoutes;