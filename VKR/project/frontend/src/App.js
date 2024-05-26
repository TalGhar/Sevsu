import './App.css';
import AdminAuthForm from './components/AdminAuthForm';
import AdminComponent from './components/AdminComponent';

import { Routes, Route } from 'react-router-dom';
import AdminNavBar from './components/AdminNavBar';
import AdminCreateUser from './components/AdminCreateUser';
import AdminShowUsers from './components/AdminShowUsers';
import AdminCreateWallet from './components/AdminCreateWallet';
import AdminShowWallets from './components/AdminShowWallets';
import ProtectedRoute from './routes/ProtectedRoute';

function App() {

  return (
    <Routes>
      <Route element={<AdminNavBar />}>

        <Route path="admin" element={<AdminComponent />} />
        <Route path="admin/create-user" element={<AdminCreateUser />} />
        <Route path="admin/show-users" element={<AdminShowUsers />} />
        <Route path="admin/create-wallet" element={<AdminCreateWallet />} />
        <Route path="admin/show-wallets" element={<AdminShowWallets />} />

      </Route>
      <Route path="admin/login" element={<AdminAuthForm />} />
    </Routes >
  );
}

export default App;
