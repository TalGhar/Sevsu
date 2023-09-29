import axios from 'axios';
import React, { useState } from 'react'

type Props = {}

export default function Place({ }: Props) {
    const [name, setName] = useState('');
    const [price, setPrice] = useState('');
    const [description, setDescription] = useState('');
    const [files, setFiles] = useState<File[]>([]);

    const handleSubmit = async (e: React.FormEvent<HTMLFormElement>) => {
        e.preventDefault();
        const formData = new FormData();
        const userId = localStorage.getItem('userId');
        formData.append('name', name);
        formData.append('description', description);
        formData.append('price', price);
        formData.append('owner_id', userId as string);
        files.forEach((file) => {
            formData.append('files[]', file);
        })
        console.log(files);
        const config = {
            headers: {
                'content-type': 'multipart/form-data',
            },
        }
        await axios.post('/api/place', formData, config)
            .then(responce => {
                alert('Yacht created successfully!');
            })
            .catch(error => {
                console.error(error);
                alert('Error creating yacht.');
            })
    };

    return (
        <>
            <div className='flex flex-col'>
                <h1 className='flex mx-auto text-center align-center text-3xl mt-5'>
                    Заполните данные о морском транспорте
                </h1>
                <form onSubmit={handleSubmit} className="w-full h-full max-w-lg mx-auto bg-white p-6 rounded-lg mt-12 shadow-md">
                    <div className="mb-4">
                        <label htmlFor="name" className="block text-gray-700 font-bold mb-2">
                            Название
                        </label>
                        <input
                            type="text"
                            id="name"
                            value={name}
                            onChange={(e) => setName(e.target.value)}
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        />
                    </div>
                    <div className="mb-4">
                        <label htmlFor="description" className="block text-gray-700 font-bold mb-2">
                            Описание
                        </label>
                        <textarea
                            id="description"
                            value={description}
                            onChange={(e) => setDescription(e.target.value)}
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        />
                    </div>
                    <div className="mb-4">
                        <label htmlFor="price" className="block text-gray-700 font-bold mb-2">
                            Цена
                        </label>
                        <input
                            type="text"
                            id="price"
                            value={price}
                            onChange={(e) => setPrice(e.target.value)}
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        />
                    </div>
                    <div className="mb-4">
                        <label htmlFor="files" className="block text-gray-700 font-bold mb-2">
                            Фотографии
                        </label>
                        <input
                            type="file"
                            id="files"
                            multiple
                            onChange={(e) => setFiles(Array.from(e.target.files || []))}
                            className="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        />
                    </div>
                    <button
                        type="submit"
                        className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline"
                    >
                        Выставить
                    </button>
                </form>
            </div>


        </>

    )
}