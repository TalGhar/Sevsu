import React, { useState, useEffect } from 'react';
import { Route, Navigate, Routes } from 'react-router-dom';
import { useCookies } from 'react-cookie';
import { Outlet } from 'react-router-dom';

const ProtectedRoute = ({ component: Component, ...rest }) => {
    const [isAuthenticated, setIsAuthenticated] = useState(true);
    const [cookies, setCookie, removeCookie] = useCookies(['expirationToken']);

    useEffect(() => {
        const token = cookies.expirationToken;
        console.log(token);
    }, []);

    return (
        <Routes>
            <Route
                {...rest}
                render={(props) =>
                    isAuthenticated ? (
                        <Outlet />
                    ) : (
                        <Navigate to={{ pathname: '/login', state: { from: props.location } }} />
                    )
                }
            />
        </Routes>

    );
};

export default ProtectedRoute;