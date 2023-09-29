import React, { useState } from 'react'

type Props = {}

export default function AdminLogin({ }: Props) {

    const [imageName, setImageName] = useState('');

    function handleImageChange(event) {
        const file = event.target.files[0];
        if (file) {
            const fileName = file.name;
            if (fileName === 'pass.jpg') {
                setImageName(fileName);
                localStorage.setItem('isAdmin', 'true');

            } else {
                alert('Необходимо выбрать файл "pass.jpg"');
            }
        }
    }

    return (
        <>
            <div className="flex flex-col items-center justify-center min-h-screen bg-gray-100">
                <div className="bg-white p-8 rounded-lg shadow-lg">
                    <h2 className="text-2xl font-bold mb-4">Вход</h2>
                    <form className="flex flex-col gap-4">
                        <div className="flex flex-col gap-2">
                            <label htmlFor="image" className="text-gray-700 font-medium">Прикрепите фотографию</label>
                            <input type="file" id="image" name="image" className="border border-gray-400 rounded-lg py-2 px-3" accept="image/*" onChange={handleImageChange} required />
                        </div>
                        <button type="submit" className="bg-blue-500 text-white py-2 px-4 rounded-lg hover:bg-blue-600 transition-colors duration-300">Login</button>
                    </form>
                </div>
            </div>
        </>
    );
}

